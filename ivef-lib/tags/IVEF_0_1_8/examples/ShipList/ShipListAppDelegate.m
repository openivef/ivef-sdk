//
//  ShipListAppDelegate.m
//  ShipList
//
//  Created by Chris on 30/04/10.


#import "ShipListAppDelegate.h"

@implementation ShipListAppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
	// Create a placeholder for the ships
    ships = [[NSMutableDictionary alloc] init];
    
    // Create the URL request.
    serverURL = [[NSURL URLWithString:@"http://www.openivef.org/example/ivef.php?user=chris&password=lukassen"] retain];
    
    // Create a parser for the messages
    parser = [[ILParser alloc] init];
    
    // attach to the signals of the parser
    [[NSNotificationCenter defaultCenter] addObserver:self 
                                             selector:@selector(handleMessage:) 
                                                 name:@"NewILMSG_VesselData" 
                                               object:parser];
    // update the information every minute
    [NSTimer scheduledTimerWithTimeInterval:60.0 
                                     target:self 
                                   selector:@selector(timerFireMethod:) 
                                   userInfo:nil 
                                    repeats:YES];
    
    // fire first shot now
    [self timerFireMethod: nil];
}

- (void)timerFireMethod:(NSTimer*)theTimer {
    
    // create the connection with the request and start loading the data
    NSString *data = [NSString stringWithContentsOfURL: serverURL
                                              encoding: NSUTF8StringEncoding
                                                 error: nil];
    
    if (data) {
        // if we get some data, parse it for IVEF messages
        [parser parseXMLString: data andBuffer: NO];
        
        // set the content of the view
        [controller setContent: [ships allValues]];
    }
}

- (void)handleMessage:(NSNotification *)notification {
    
    // get the message
    ILMSG_VesselData *msg = [[notification userInfo] objectForKey:@"Data"];
    
    for (ILVesselData *vessel in [[msg body] vesselDatas]) {
        
        if ([[[vessel posReport] lost] isEqualToString:@"yes"]) {
            // remove the ship
            [ships removeObjectForKey: [NSString stringWithFormat:@"%d", [[vessel posReport] ident]]]; 
            
        } else {
            // update name, destination and ETA
            NSString *name, *dest;
            NSDate *eta;
            
            // use only the first static data
            if ([vessel countOfStaticDatas] > 0) {
                name = [[vessel staticDataAt:0] shipName];
                
                // use only the first voyage                
                if ([vessel countOfVoyages] > 0) {
                    dest = [[vessel voyageAt:0] destination];
                    eta = [[vessel voyageAt:0] ETA];
                }
                
                if (name != nil) {
                    NSMutableDictionary *details = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                                                    name, @"Name",
                                                    dest, @"Destination",
                                                    eta, @"ETA", 
                                                    nil];
                    [ships setObject:details forKey: [NSString stringWithFormat:@"%d", [[vessel posReport] ident]]];
                    
                }
            }
        }
    }
}

@end
