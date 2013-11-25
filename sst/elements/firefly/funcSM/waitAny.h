// Copyright 2013 Sandia Corporation. Under the terms
// of Contract DE-AC04-94AL85000 with Sandia Corporation, the U.S.
// Government retains certain rights in this software.
//
// Copyright (c) 2013, Sandia Corporation
// All rights reserved.
//
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.

#ifndef COMPONENTS_FIREFLY_FUNCSM_WAITANY_H
#define COMPONENTS_FIREFLY_FUNCSM_WAITANY_H

#include "funcSM/api.h"
#include "funcSM/event.h"
#include "longMsgProtocol.h"

namespace SST {
namespace Firefly {

class WaitAnyFuncSM :  public FunctionSMInterface
{
  public:
    WaitAnyFuncSM( SST::Params& params );

    virtual void handleStartEvent( SST::Event*, Retval& );
    virtual void handleEnterEvent( Retval& );
    
    virtual std::string protocolName() { return "LongMsgProtocol"; }

  private:
    LongMsgProtocol* proto() { return static_cast<LongMsgProtocol*>(m_proto); }

    WaitAnyStartEvent* m_event;
};

}
}

#endif
