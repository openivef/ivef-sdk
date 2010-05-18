#import <Foundation/Foundation.h>
#import "Handler.h"

int main (int argc, const char * argv[]) {
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    Handler *handler = [[Handler alloc] init];
    [handler parseStdIn];
    
    [pool drain];
    return 0;
}
