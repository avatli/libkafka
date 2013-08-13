//////////////////////////////////////////////////////////////////
//                                                              //
// libkafka - C/C++ client for Apache Kafka v0.8+               //
//                                                              //
// David Tompkins -- 8/8/2013                                   //
// http://dt.org/                                               //
//                                                              //
// Copyright (c) 2013 by David Tompkins.                        //
//                                                              //
//////////////////////////////////////////////////////////////////
//                                                              //
// This program is free software; you can redistribute it       //
// and/or modify it under the terms of the GNU General Public   //
// License as published by the Free Software Foundation.        //
//                                                              //
// This program is distributed in the hope that it will be      //
// useful, but WITHOUT ANY WARRANTY; without even the implied   //
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      //
// PURPOSE. See the GNU General Public License for more details //
//                                                              //
// You should have received a copy of the GNU General Public    //
// License along with this program; if not, write to the Free   //
// Software Foundation, Inc., 59 Temple Place, Suite 330,       //
// Boston, MA 02111-1307 USA                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef PARTITIONMETADATA_H
#define PARTITIONMETADATA_H

#include <string>
#include <Debug.h>
#include <Packet.h>
#include <PartitionMetadata.h>
#include <WireFormatter.h>
#include <PacketWriter.h>

using namespace std;

class PartitionMetadata : public WireFormatter, public PacketWriter
{
  public:

    short int partitionErrorCode;
    int partitionId;
    int leader;
    int replicaArraySize;
    int *replicaArray;
    int isrArraySize;
    int *isrArray;

    PartitionMetadata(Packet *packet);
    PartitionMetadata(short int partitionErrorCode, int partitionId, int leader, int replicaArraySize, int *replicaArray, int isrArraySize, int *isrArray);

    unsigned char* toWireFormat(bool updateSize = true);

  private:

    bool releaseArrays;
};

ostream& operator<< (ostream& os, const PartitionMetadata& b);
inline bool operator==(const PartitionMetadata& lhs, const PartitionMetadata& rhs) { return ((lhs.partitionErrorCode==rhs.partitionErrorCode)&&(lhs.partitionId==rhs.partitionId)&&(lhs.leader==rhs.leader)); }
inline bool operator!=(const PartitionMetadata& lhs, const PartitionMetadata& rhs) { return !operator==(lhs,rhs); }

#endif /* PARTITIONMETADATA_H */