//
//  ServerManager.h
//  Chicken of the VNC
//
//  Created by Jared McIntyre on Sat Jan 24 2004.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//


#import <Foundation/Foundation.h>
#import "IServerData.h"

/**
 *  ServerDataManager manages all known accessible servers in Chicken of the VNC
 *  including saved server from preferences, rendezvous servers, etc. Servers will
 *  be accessible through the IServerData protocol. Users should not attempt to access
 *  the servers as their specific class type since those classes may change in ways
 *  incompatible to your code (including adding new server classes), but the protocol
 *  should not.
 *  <BR><BR>
 *  This is a singleton class. Always access the class through the sharedInstance
 *  function. Do not create an instance yourself.
 */
@interface ServerDataManager : NSObject {
	NSMutableDictionary* servers;
}

#define ServerListChangeMsg @"ServerListChangeMsg"

/**
 *  Accessor method to fetch the singleton instance for this class. Use this method
 *  instead of creating an instance of your own.
 *  @return Shared singleton instance of the ServerDataManager class. */
+ (ServerDataManager*) sharedInstance;

/*
 *  Allows access to all servers managed by ServerDataManager.
 *  @return The enumerator that can be used to enumerate through all servers. 
 */
- (NSEnumerator*) getServerEnumerator;

/*
 *  Retrieves a server by its name. The retrieval process is case sensative.
 *  @param name The name of the server you want to retrieve.
 *  @return The server whose name matches the requested one or nil if the server
 *  was not found.
 */
- (id<IServerData>)getServerWithName:(NSString*)name;

/*
 *  Retrieves a server by its index value.
 *  @param index The index of the server you want to retrieve.
 *  @return The server at the requested index or nil if the server
 *  was not found.
 */
- (id<IServerData>)getServerAtIndex:(int)index;

/*
 *  Deletes the specified server
 *  @param server The server to be deleted.
 */
- (void)removeServer:(id<IServerData>)server;

/*
 *  Adds a new server to the server list. The namepassed in becomes the name of the
 *  server unless that name is already in use. If the the name is in use, an underscore
 *  followed by a number will be added to the name so that it is unique.
 *  @param name The name to create the server as.
 *  @return The created server.
 */
- (id<IServerData>)createServerByName:(NSString*)name;

@end
