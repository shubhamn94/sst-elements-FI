// Copyright 2009-2010 Sandia Corporation. Under the terms
// of Contract DE-AC04-94AL85000 with Sandia Corporation, the U.S.
// Government retains certain rights in this software.
// 
// Copyright (c) 2009-2010, Sandia Corporation
// All rights reserved.
// 
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.

#ifndef  IRIS_SST_LIB_CC_INC
#define  IRIS_SST_LIB_CC_INC
#include <sst_config.h>
#include "sst/core/serialization/element.h"

#include <sst/core/element.h>
#include "router.h"
#include "ninterface.h"

static SST::Component* 
create_router(SST::ComponentId_t id, 
                SST::Component::Params_t& params)
{
    return new Router( id, params );
}

static SST::Component* 
create_ninterface(SST::ComponentId_t id, 
                SST::Component::Params_t& params)
{
    return new NInterface( id, params );
}

static const SST::ElementInfoComponent components[] = {
    { "router",
      "Iris Router",
      NULL,
      create_router,
    },
    { "ninterface",
      "Interface for iris terminal and router",
      NULL,
      create_ninterface,
    },
    { NULL, NULL, NULL, NULL }
};

extern "C" {
    SST::ElementLibraryInfo iris_eli = {
        "iris",
        "Trying Desperately to switch out redstorm",
        components,
    };
}
#endif   /* ----- #ifndef IRIS_SST_LIB_CC_INC  ----- */
