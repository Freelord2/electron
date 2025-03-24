// Copyright (c) 2025 Microsoft GmbH.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ELECTRON_SHELL_BROWSER_LINUX_X11_UTIL_H_
#define ELECTRON_SHELL_BROWSER_LINUX_X11_UTIL_H_

#include "ui/ozone/public/ozone_platform.h"

namespace x11_util {

bool IsX11() {
  return ui::OzonePlatform::GetInstance()
      ->GetPlatformProperties()
      .electron_can_call_x11;
}

}  // namespace x11_util

#endif  // ELECTRON_SHELL_BROWSER_LINUX_X11_UTIL_H_
