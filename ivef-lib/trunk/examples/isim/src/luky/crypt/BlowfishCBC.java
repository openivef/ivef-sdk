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


/******************************************************************************
 * implementation of the Blowfish encryption algorithm in CBC mode
 * <p>
 *
 *  <ul>
 *   <li> 1.0.0 - Release under LGPL (a.b.c) (a=major, b=class compatible, c=api compatible)</li>
 * </ul>
 *
 * @author Markus Hahn <markus_hahn@gmx.net>
 * @version 1.0.0
 ******************************************************************************/
public class BlowfishCBC extends BlowfishECB {

    // here we hold the CBC IV
    long m_lCBCIV;

    /**
     * get the current CBC IV (for cipher resets)
     * @return current CBC IV
     */
    public long getCBCIV() {
        return m_lCBCIV;
    }

    /**
     * set the current CBC IV (for cipher resets)
     * @param lNewCBCIV the new CBC IV
     */
    public void setCBCIV(long lNewCBCIV) {
        m_lCBCIV = lNewCBCIV;
    }

    /**
     * set the current CBC IV (for cipher resets)
     * @param newCBCIV the new CBC IV  in network byte ordered array
     */
    public void setCBCIV(byte[] newCBCIV) {
        m_lCBCIV = BinConverter.byteArrayToLong(newCBCIV, 0);
    }

    /**
     * constructor
     * @param bfkey key material, up to MAXKEYLENGTH bytes
     * @param lInitCBCIV the CBC IV
     */
    public BlowfishCBC(byte[] bfkey,
            long lInitCBCIV) {
        super(bfkey);

        // store the CBCB IV
        setCBCIV(lInitCBCIV);
    }

    /**
     * encrypts a byte buffer (should be aligned to an 8 byte border) to itself
     * @param buffer buffer to encrypt
     */
    public void encrypt(byte[] buffer) {

        int nLen = buffer.length;
        long lTemp;

        for (int nI = 0; nI < nLen; nI += 8) {
            // encrypt a temporary 64bit block
            lTemp = BinConverter.byteArrayToLong(buffer, nI);
            lTemp = encryptBlock(lTemp);
            BinConverter.longToByteArray(lTemp, buffer, nI);
        }
    }

    /**
     * decrypts a byte buffer (should be aligned to an 8 byte border) to itself
     * @param buffer buffer to decrypt
     */
    public void  decrypt(byte[] buffer) {
        int nLen = buffer.length;
        long lTemp;

        for (int nI = 0; nI < nLen; nI += 8) {
            // decrypt over a temporary 64bit block
            lTemp = BinConverter.byteArrayToLong(buffer, nI);
            lTemp = decryptBlock(lTemp);
            BinConverter.longToByteArray(lTemp, buffer, nI);
        }
    }
}
