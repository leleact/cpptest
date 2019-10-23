#pragma once

#ifndef _HEADER_ONLY_H
#define _HEADER_ONLY_H

namespace header_only {

struct header_only {
  inline const char *echo(const char *__echo) { return __echo; }
};
} // namespace header_only

#endif
