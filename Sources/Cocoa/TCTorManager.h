/*
 *  TCTorManager.h
 *
 *  Copyright 2010 Avérous Julien-Pierre
 *
 *  This file is part of TorChat.
 *
 *  TorChat is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  TorChat is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TorChat.  If not, see <http://www.gnu.org/licenses/>.
 *
 */



#import <Cocoa/Cocoa.h>



/*
** Forward
*/
#pragma mark -
#pragma mark Forward

class TCConfig;



/*
** Notify
*/
#pragma mark -
#pragma mark Nority

#define TCTorManagerStatusChanged	@"TCTorManagerStatusChanged"
#define TCTorManagerInfoHostNameKey	@"hostname"
#define TCTorManagerInfoRunningKey	@"running"



/*
** TCTorManager
*/
#pragma mark -
#pragma mark TCTorManager

@interface TCTorManager : NSObject {
@private
	
    BOOL				_running;
	
	NSTask				*_task;
	dispatch_source_t	errSource;
	dispatch_source_t	outSource;
	
	NSString			*_hidden;
	
	dispatch_queue_t	mainQueue;
	dispatch_source_t	testTimer;
}

// -- Singleton --
+ (TCTorManager *)sharedManager;

// -- Running --
- (void)startWithConfig:(TCConfig *)config;
- (void)stop;

- (BOOL)isRunning;

// -- Property --
- (NSString *)hiddenHostname;

@end