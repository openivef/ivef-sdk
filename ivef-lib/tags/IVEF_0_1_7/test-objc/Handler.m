//
//  Handler.m
//  testobjc
//
//  Created by aqua on 11/04/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "Handler.h"


@implementation Handler


- (void)parseStdIn {
    
    // setup the pipes
    fdin = [NSFileHandle fileHandleWithStandardInput];
    fdout = [NSFileHandle fileHandleWithStandardOutput];
    
    // create a parser
    ILParser *parser = [[ILParser alloc] init];
    
    // attach to all signals of the parser
    [[NSNotificationCenter defaultCenter] addObserver:self 
                                             selector:@selector(handleMessage:) 
                                                 name:nil 
                                               object:parser];

    // read from stdin until end
    [fdout writeData: [@"TestApp ready for input\n" dataUsingEncoding: NSUTF8StringEncoding]];
    NSData *data = [fdin readDataToEndOfFile];
    NSString *dataAsString = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];
    
    // parse it
    [parser parseXMLString:dataAsString  andBuffer:YES];
    
    // shut down
    [fdout writeData: [@"TestApp shutting down\n" dataUsingEncoding: NSUTF8StringEncoding]];
}

- (void)handleMessage:(NSNotification *)notification {
    
    // get the message
    id ivefMessage = [[notification userInfo] objectForKey:@"Data"];
    
    // create the message as a string
    // should call the selector indirect and cast the result to avoid the compiler warning
    NSString *message = [NSString stringWithFormat:@"%@%@\n", [ivefMessage stringValue], [ivefMessage XML]];    
    
    // write it to stdout
    [fdout writeData:[message dataUsingEncoding:NSUTF8StringEncoding]];
}

@end
