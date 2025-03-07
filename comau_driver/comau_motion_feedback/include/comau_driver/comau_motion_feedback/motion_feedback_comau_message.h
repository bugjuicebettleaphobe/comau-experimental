
/*********************************************************************
 *
 * Provides the Structures to manage the MotionFeedbackComau.msg
 * 
 * Authors: Alberto Marini (alberto.marini@itia.cnr.it)
 *          Enrico Villagrossi (enrico.villagrossi@itia.cnr.it)
 *          Manuel Beschi (manuel.beschi@itia.cnr.it)
 *          Nicola Pedrocchi (nicola.pedrocchi@itia.cnr.it)
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2016, National Research Council of Italy, Institute of Industrial Technologies and Automation
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the National Research Council of Italy nor the 
 *     names of its contributors may be used to endorse or promote products 
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#ifndef MOTION_FEEDBACK_COMAU_MESSAGE_H
#define MOTION_FEEDBACK_COMAU_MESSAGE_H

#include <simple_message/typed_message.h>
#include <simple_message/shared_types.h>

#include <comau_msgs/comau_simple_message.h>
#include <comau_driver/comau_motion_feedback/motion_feedback_comau.h>


namespace comau
{
  /** @ns motion_feedback_comau_message */
namespace motion_feedback_comau_message
{


/**
 * \brief Class encapsulated motion feedback message generation methods
 * (either to or from a industrial::simple_message::SimpleMessage type.
 *
 * THIS CLASS IS NOT THREAD-SAFE
 *
 */
class MotionFeedbackComauMessage : public industrial::typed_message::TypedMessage
{
public:
  /**
   * \brief Default constructor
   *
   * This method creates an empty message.
   *
   */
  MotionFeedbackComauMessage(void);
  /**
   * \brief Destructor
   *
   */
  ~MotionFeedbackComauMessage(void);
  /**
   * \brief Initializes message from a simple message
   *
   * \param msg: simple message to construct from
   *
   * \return true if message successfully initialized, otherwise false
   */
  bool init(industrial::simple_message::SimpleMessage & msg);

  /**
   * \brief Initializes message from a motion feedback structure
   *
   * \param feedback: motion feedback strcutre to initialize from
   *
   */
  void init(comau::motion_feedback_comau::MotionFeedbackComau & feedback);

  /**
   * \brief Initializes a new motion feedback message
   *
   */
  void init();


  // Overrides - SimpleSerialize
  bool load(industrial::byte_array::ByteArray *buffer);
  bool unload(industrial::byte_array::ByteArray *buffer);

  unsigned int byteLength()
  {
    return this->feedback_.byteLength();
  }


  
  comau::motion_feedback_comau::MotionFeedbackComau feedback_;

};

} // motion_feedback_comau_message
} // comau

#endif /* MOTION_FEEDBACK_COMAU_MESSAGE_H */
