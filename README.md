# ivef-sdk
_Convert ivef.xsd to C++, JAVA and PHP code to easily read or write IVEF_

Makes a parser for IVEF XML in a few steps.
* Step 1: Make a schema to code executable. 
        Needs Qt library
* Step 2: The executable will generate classes for C++, JAVA or PHP based on a xsd.
        ivef.xsd is used per default, but the schema-to-code can be used for any xsd file.
* Step 3: Build the parser library

Examples for how the library can be used to generate XML or read XML are available in the example directory.

Build: Use _qmake_ and then _make_. Results (schema to code executable, libraries and examples) are in build directory.
