// ======================================================================
// \title  ScopeLock_Test.hpp
// \author ldmiller
// \brief  hpp file for ScopeLock_Test component implementation class
// ======================================================================

#ifndef Components_ScopeLock_Test_HPP
#define Components_ScopeLock_Test_HPP

#include "Components/ScopeLock_Test/ScopeLock_TestComponentAc.hpp"
#include "Templated_Helper.hpp"

namespace Components {

class ScopeLock_Test : public ScopeLock_TestComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct ScopeLock_Test object
    ScopeLock_Test(const char* const compName  //!< The component name
    );

    //! Destroy ScopeLock_Test object
    ~ScopeLock_Test();

  PRIVATE:
    // ----------------------------------------------------------------------
    // Handler implementations for typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for run
    //!
    //! for receiving calls from the rate group
    void run_handler(FwIndexType portNum,  //!< The port number
                     U32 context           //!< The call order
                     ) override;

  PRIVATE:
    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command RunTest
    //!
    //! Run the test
    void RunTest_cmdHandler(FwOpcodeType opCode,  //!< The opcode
                            U32 cmdSeq            //!< The command sequence number
                            ) override;

    util::MyHelper<U32> templated_helper;
    util::MyTemplatedClass<U32> templated_class;
};

}  // namespace Components

#endif
