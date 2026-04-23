#include "sapien/profiler.h"

#if defined(SAPIEN_PROFILE) && !defined(NVTX_DISABLE)
#include <nvtx3/nvToolsExt.h>
#endif

namespace sapien {

#if defined(SAPIEN_PROFILE) && !defined(NVTX_DISABLE)
void ProfilerEvent(char const *name) { nvtxMarkA(name); }
void ProfilerBlockBegin(char const *name) { nvtxRangePushA(name); }
void ProfilerBlockEnd() { nvtxRangePop(); }
#else
void ProfilerEvent(char const *name) {}
void ProfilerBlockBegin(char const *name) {}
void ProfilerBlockEnd() {}
#endif

} // namespace sapien
