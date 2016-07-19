/*
 * Copyright (c) Microsoft Corporation. All rights reserved.
 */

#import "AVALogContainer.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^AVASendAsyncCompletionHandler)(NSError *error,
                                              NSUInteger statusCode,
                                              NSString *batchId);
@protocol AVASender <NSObject>

@required
/**
 * Initialize the Sender
 *
 * @param url Base url
 * @param headers Http headers
 * @param queryStrings array of query strings
 */
- (id)initWithBaseUrl:(NSString *)baseUrl headers:(NSDictionary *)headers queryStrings:(NSDictionary*)queryStrings;

/**
 * Send logs in batch
 *
 * @param logs Batched log
 * @param queue Queue for dispatching the completion handler
 * @param handler Completion handler
 */
- (NSNumber *)sendAsync:(AVALogContainer *)logs
              callbackQueue:(dispatch_queue_t)callbackQueue
          completionHandler:(AVASendAsyncCompletionHandler)handler;

@end
NS_ASSUME_NONNULL_END