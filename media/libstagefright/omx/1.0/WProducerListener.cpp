/*
 * Copyright 2016, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "WProducerListener.h"

namespace android {
namespace hardware {
namespace media {
namespace omx {
namespace V1_0 {
namespace implementation {

// TWProducerListener
TWProducerListener::TWProducerListener(
        sp<BProducerListener> const& base):
    mBase(base) {
}

Return<void> TWProducerListener::onBufferReleased() {
    mBase->onBufferReleased();
    return Void();
}

Return<bool> TWProducerListener::needsReleaseNotify() {
    return mBase->needsReleaseNotify();
}

// LWProducerListener
LWProducerListener::LWProducerListener(
        sp<HProducerListener> const& base):
    mBase(base) {
}

void LWProducerListener::onBufferReleased() {
    mBase->onBufferReleased();
}

bool LWProducerListener::needsReleaseNotify() {
    return static_cast<bool>(mBase->needsReleaseNotify());
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace omx
}  // namespace media
}  // namespace hardware
}  // namespace android