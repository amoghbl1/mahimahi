/* -*-mode:c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include <vector>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <paths.h>
#include <grp.h>
#include <cstdlib>
#include <fstream>
#include <resolv.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <fstream>

#include "util.hh"
#include "system_runner.hh"
#include "http_response.hh"
#include "http_record.pb.h"
#include "file_descriptor.hh"

using namespace std;

int main( int argc, char *argv[] )
{
    try {
        if ( argc < 1 ) {
            throw Exception( "Usage", string( argv[ 0 ] ) + " replayshell_file" );
        }

        string proto_file = argv[ 1 ];

        MahimahiProtobufs::RequestResponse protobuf;

        {
            FileDescriptor old( SystemCall( "open ", open( proto_file.c_str(), O_RDONLY ) ) );

            /* store previous version (before modification) of req/res protobuf */
            if ( not protobuf.ParseFromFileDescriptor( old.num() ) ) {
                throw Exception( proto_file, "invalid HTTP request/response" );
            }
        }

        MahimahiProtobufs::RequestResponse final_protobuf;
        MahimahiProtobufs::HTTPMessage new_response( protobuf.response() );

        cout << new_response.first_line() << endl;
        /* use modified text file as new response body */
        for ( int i = 0; i < new_response.header_size(); i++ ) {
            HTTPHeader current_header( new_response.header(i) );
            cout << current_header.key() << ":" << current_header.value() << endl;
        }
    } catch ( const Exception & e ) {
        e.perror();
        return EXIT_FAILURE;
    }
}
