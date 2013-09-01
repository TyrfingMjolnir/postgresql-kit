
#import <Foundation/Foundation.h>
#import <PGClientKit/PGClientKit.h>

// forward declarations
@protocol PGConnectionControllerDelegate;

// PGConnectionController
@interface PGConnectionController : NSObject {
	NSMutableDictionary* _connections;
	NSMutableDictionary* _urls;
}

// properties
@property (weak, nonatomic) id<PGConnectionControllerDelegate> delegate;

// methods
-(PGConnection* )createConnectionWithURL:(NSURL* )url forKey:(NSUInteger)key;
-(PGConnection* )connectionForKey:(NSUInteger)key;
-(BOOL)openConnectionForKey:(NSUInteger)key;
-(void)closeConnectionForKey:(NSUInteger)key;
-(void)closeAllConnections;

@end

// delegate protocol
@protocol PGConnectionControllerDelegate <NSObject>
@optional
-(void)connectionOpeningWithKey:(NSUInteger)key;
-(void)connectionOpenWithKey:(NSUInteger)key;
-(void)connectionRejectedWithKey:(NSUInteger)key error:(NSError* )error;
-(void)connectionNeedsPasswordWithKey:(NSUInteger)key;
-(void)connectionClosedWithKey:(NSUInteger)key;
@end

