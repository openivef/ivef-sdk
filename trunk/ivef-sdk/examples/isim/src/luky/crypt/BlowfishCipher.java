/******************************************************************************
 *   Copyright (C) 2006 Chris Lukassen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 ******************************************************************************/
package luky.crypt;


import java.util.*;


/******************************************************************************
 * A Blowfish Ciphering object that can be used to crypt and decrypt strings
 *  Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *   <li> 1.01 - added interface for byte arrays </li>
 *   <li> 2.00 - port to luky </li>
 * </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 2.00
 ******************************************************************************/
public class BlowfishCipher {
    private Random random = null;
    private BlowfishCBC m_bfish = null;

    /**************************************************************************
     * default constructor
     * @param key the key which is used to decrypt or encrypt the strings
     * @param rand the randomizer that is used to generate random numbers
     **************************************************************************/
    public BlowfishCipher(String key, Random rand) {
        super();
        m_bfish = new BlowfishCBC(key.getBytes(), 0);
        random = rand;
    }

    /**************************************************************************
     * default constructor
     * @param key the key which is used to decrypt or encrypt the data
     * @param rand the randomizer that is used to generate random numbers
     **************************************************************************/
    public BlowfishCipher(byte[] key, Random rand) {
        super();
        m_bfish = new BlowfishCBC(key, 0);
        random = rand;
    }

    /**************************************************************************
     * encrypt a string
     * @param input the string that is to be encrypted
     * @return the encrypted string
     **************************************************************************/
    public String encrypt(String input) {
        // get the byte text
        byte[] plainText = input.getBytes();

        return BinConverter.bytesToBinHex(encrypt(plainText));
    }

    /**************************************************************************
     * encrypt a byte array
     * @param plainText the byte array that is to be encrypted
     * @return the encrypted byte array
     **************************************************************************/
    public byte[] encrypt(byte[] plainText) {
        // get the IV
        long lCBCIV = random.nextLong();

        // allocate the buffer (align to the next 8 byte border plus padding)
        int nLen = plainText.length;
        byte[] buf = new byte[(nLen & 0xfffffff8) + 8];

        // copy all bytes of the input into the buffer (use network byte order)
        int nI;
        int nPos = 0;

        for (nI = 0; nI < nLen; nI++) {
            buf[nPos++] = plainText[nI];
        }

        // pad the rest with the PKCS5 scheme
        byte bPadVal = (byte) (buf.length - (nLen));

        while (nPos < buf.length) {
            buf[nPos++] = bPadVal;
        }

        // create the encryptor
        m_bfish.setCBCIV(lCBCIV);

        // encrypt the buffer
        m_bfish.encrypt(buf);

        // return the binhex string
        byte[] newCBCIV = new byte[BlowfishCBC.BLOCKSIZE];

        BinConverter.longToByteArray(lCBCIV, newCBCIV, 0);

        byte[] result = new byte[newCBCIV.length + buf.length];

        System.arraycopy(newCBCIV, 0, result, 0, newCBCIV.length);
        System.arraycopy(buf, 0, result, newCBCIV.length, buf.length);

        return result;
    }

    /**************************************************************************
     * decrypt a string
     * @param input the string that is to be decrypt
     * @return the decrypted string or null in case of an error
     **************************************************************************/
    public String decrypt(String input) {
        try {
            // make it a byte array
            // get the byte text
            byte[] cipherText = new byte[input.length() / 2];

            // convert the input
            BinConverter.binHexToBytes(input, cipherText, 0, 0, input.length());

            // convert it useing byte array
            return new String(decrypt(cipherText));
        } catch (Exception e) {
            // strange things can happen with garbage data
            return null;
        }
    }

    /**************************************************************************
     * decrypt a byte array
     * @param cipherText the byte array that is to be decrypt
     * @return the decrypted byte array or null in case of an error
     **************************************************************************/
    public byte[] decrypt(byte[] cipherText) {

        // get the number of bytes
        int nLen = cipherText.length;

        // does the given stuff make sense (at least the CBC IV)?
        if (nLen < BlowfishECB.BLOCKSIZE) {
            return null;
        }

        // get the CBC IV
        byte[] cbciv = new byte[BlowfishCBC.BLOCKSIZE];

        System.arraycopy(cipherText, 0, cbciv, 0, BlowfishCBC.BLOCKSIZE);

        // (got it)
        m_bfish.setCBCIV(cbciv);

        // something left to decrypt?
        nLen -= BlowfishCBC.BLOCKSIZE;
        if (nLen == 0) {
            return null;
        }

        // get all data bytes now
        byte[] buf = new byte[nLen];

        System.arraycopy(cipherText, BlowfishCBC.BLOCKSIZE, buf, 0, nLen);
        // System.arraycopy(cipherText, 0, buf, 0, nLen);

        // decrypt the buffer
        m_bfish.decrypt(buf);

        // get the last padding byte
        int nPadByte = (int) buf[buf.length - 1] & 0x0ff;

        // ( try to get all information if the padding doesn't seem to be correct)
        if ((nPadByte > 8) || (nPadByte < 0)) {
            nPadByte = 0;
        }

        // return result without padding byte
        byte[] res = new byte[buf.length - nPadByte];

        System.arraycopy(buf, 0, res, 0, res.length);

        return res;
    }
}
