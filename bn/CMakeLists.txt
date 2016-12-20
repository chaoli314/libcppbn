project(bn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(HEADER_FILES
        BasicClass.h

        Node.h
        BayesianNetwork.h


        ADTree.h
        contingency_table.h

        var.h
        sorted_set.h
        varset.h
        Factor.h

        HuginFormatFile.h
        typedefs.h
        )

set(SOURCE_FILES
        BasicClass.cc
        )

add_library(bn STATIC ${SOURCE_FILES} ${HEADER_FILES})
