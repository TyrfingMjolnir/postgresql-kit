

#import "PGSchemaProductNV.h"
#import "PGSchemaProductOp.h"

@interface PGSchema (Private)
+(NSError* )errorWithCode:(PGSchemaErrorType)code description:(NSString* )description path:(NSString* )path;
-(BOOL)_addSearchPath:(NSString* )path;
-(NSArray* )_subpathsAtPath:(NSString* )path;
-(NSArray* )_productsAtPath:(NSString* )path error:(NSError** )error;
-(BOOL)_hasProductTableWithError:(NSError** )error;
-(BOOL)_hasProductInstalled:(PGSchemaProduct* )product error:(NSError** )error;
-(BOOL)_checkDependentProduct:(PGSchemaProduct* )product error:(NSError** )error;
@end
