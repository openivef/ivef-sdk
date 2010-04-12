//
//  Handler.h
//  testobjc
//
//  Created by aqua on 11/04/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IVEF/ILParser.h>

@interface Handler : NSObject {
    NSFileHandle *fdin;
    NSFileHandle *fdout;
}

- (void)parseStdIn;

@end
