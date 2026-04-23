# AGENTS

## Build Environment
- Use the conda environment named `sapien`.
- Activate it before building or testing:

```bash
conda activate sapien
```

Always choose build folder is 'sapien_build_cpu', not random folder name.

## Project Shape
- Python packaging entrypoint: `setup.py`
- Native build entrypoint: `CMakeLists.txt`
- Python extension CMake: `python/CMakeLists.txt`
- Bundled renderer: `3rd_party/sapien-vulkan-2`

## Current Build Facts
- CUDA is intended to be optional through `-DSAPIEN_CUDA=ON/OFF` in `setup.py`.
- Vulkan rendering is still a core dependency of the renderer stack.
- Linux wheel packaging currently copies bundled Vulkan assets from `vulkan_library/` and `vulkan_shader/`.
- The packaged Vulkan ICD files are NVIDIA-oriented today.

## CPU-Only Wheel Refactor Notes
- Goal interpretation: remove CUDA/GPU dependencies while still allowing Vulkan rendering through software Vulkan such as lavapipe.
- This looks feasible, but it is not a pure packaging-only change.
- Expect at least:
  - guarding unconditional CUDA headers/source paths
  - making the `svulkan2` build work without CUDA toolkit presence
  - adjusting Linux Vulkan runtime packaging/runtime detection for lavapipe or system Mesa Vulkan

## Working Style
- Prefer small refactors over broad architectural changes.
- Do not assume NVIDIA or CUDA is present.
- Preserve CPU physics-only execution even when rendering is unavailable.
