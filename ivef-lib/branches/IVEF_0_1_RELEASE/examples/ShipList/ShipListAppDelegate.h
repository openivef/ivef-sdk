//file://localhost/Users/aqua/Documents/Code/IVEFList/ShipList/English.lproj/MainMenu.xib
//  ShipListAppDelegate.h
//  ShipList
//
//  Created by Chris on 30/04/10.


#import <Cocoa/Cocoa.h>
#import <IVEF/ILParser.h>

@interface ShipListAppDelegate : NSObject <NSApplicationDelegate> {
    IBOutlet NSWindow *window;
    IBOutlet NSArrayController *controller;
    NSMutableDictionary *ships;
    NSURL *serverURL;
    ILParser *parser;
}

- (void)timerFireMethod:(NSTimer*)theTimer;

@end
