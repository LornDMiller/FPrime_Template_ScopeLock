// ======================================================================
// \title  ScopeLock_Test.cpp
// \author ldmiller
// \brief  cpp file for ScopeLock_Test component implementation class
// ======================================================================

#include "Components/ScopeLock_Test/ScopeLock_Test.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ScopeLock_Test ::ScopeLock_Test(const char* const compName) :
    ScopeLock_TestComponentBase(compName),
    templated_helper(),
    templated_class(templated_helper)
{
}

ScopeLock_Test ::~ScopeLock_Test() {}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void ScopeLock_Test ::run_handler(FwIndexType portNum, U32 context) {
    this->templated_class.DoRgStuff();
}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void ScopeLock_Test ::RunTest_cmdHandler(FwOpcodeType opCode, U32 cmdSeq) {
    this->templated_class.DoCommandStuff();
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace Components
