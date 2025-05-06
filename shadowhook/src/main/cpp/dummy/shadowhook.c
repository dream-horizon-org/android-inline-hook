// Copyright (c) 2021-2024 ByteDance Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

// Created by Kelun Cai (caikelun@bytedance.com) on 2021-04-11.

#include "shadowhook.h"


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-macros"
#define GOTO_ERR(errnum) \
  do {                   \
    r = errnum;          \
    goto err;            \
  } while (0)

static int shadowhook_init_errno = SHADOWHOOK_ERRNO_UNINIT;
static shadowhook_mode_t shadowhook_mode = SHADOWHOOK_MODE_SHARED;

const char *shadowhook_get_version(void) {
  return "shadowhook version " SHADOWHOOK_VERSION;
}

int shadowhook_init(shadowhook_mode_t mode, bool debuggable) {
  return 0;
}

int shadowhook_get_init_errno(void) {
  return shadowhook_init_errno;
}

shadowhook_mode_t shadowhook_get_mode(void) {
  return shadowhook_mode;
}

bool shadowhook_get_debuggable(void) {
  return false;
}

void shadowhook_set_debuggable(bool debuggable) {

}

bool shadowhook_get_recordable(void) {
  return false;
}

void shadowhook_set_recordable(bool recordable) {

}

int shadowhook_get_errno(void) {
  return false;
}

const char *shadowhook_to_errmsg(int error_number) {
  return "";
}

static void *shadowhook_hook_addr_impl(void *sym_addr, void *new_addr, void **orig_addr,
                                       bool ignore_symbol_check, uintptr_t caller_addr) {
  return sym_addr;
}

void *shadowhook_hook_func_addr(void *func_addr, void *new_addr, void **orig_addr) {
  const void *caller_addr = __builtin_return_address(0);
  return shadowhook_hook_addr_impl(func_addr, new_addr, orig_addr, true, (uintptr_t)caller_addr);
}

void *shadowhook_hook_sym_addr(void *sym_addr, void *new_addr, void **orig_addr) {
  const void *caller_addr = __builtin_return_address(0);
  return shadowhook_hook_addr_impl(sym_addr, new_addr, orig_addr, false, (uintptr_t)caller_addr);
}

static void *shadowhook_hook_sym_name_impl(const char *lib_name, const char *sym_name, void *new_addr,
                                           void **orig_addr, shadowhook_hooked_t hooked, void *hooked_arg,
                                           uintptr_t caller_addr) {
  return new_addr;
}

void *shadowhook_hook_sym_name(const char *lib_name, const char *sym_name, void *new_addr, void **orig_addr) {
  const void *caller_addr = __builtin_return_address(0);
  return shadowhook_hook_sym_name_impl(lib_name, sym_name, new_addr, orig_addr, NULL, NULL,
                                       (uintptr_t)caller_addr);
}

void *shadowhook_hook_sym_name_callback(const char *lib_name, const char *sym_name, void *new_addr,
                                        void **orig_addr, shadowhook_hooked_t hooked, void *hooked_arg) {
  const void *caller_addr = __builtin_return_address(0);
  return shadowhook_hook_sym_name_impl(lib_name, sym_name, new_addr, orig_addr, hooked, hooked_arg,
                                       (uintptr_t)caller_addr);
}

int shadowhook_unhook(void *stub) {
  return 0;
}

char *shadowhook_get_records(uint32_t item_flags) {
  return "";
}

void shadowhook_dump_records(int fd, uint32_t item_flags) {

}

void *shadowhook_dlopen(const char *lib_name) {
  void *handle = NULL;
  return handle;
}

void shadowhook_dlclose(void *handle) {

}

void *shadowhook_dlsym(void *handle, const char *sym_name) {
  void *addr = shadowhook_dlsym_dynsym(handle, sym_name);
  if (NULL == addr) addr = shadowhook_dlsym_symtab(handle, sym_name);
  return addr;
}

void *shadowhook_dlsym_dynsym(void *handle, const char *sym_name) {
  void *addr = NULL;
  return addr;
}

void *shadowhook_dlsym_symtab(void *handle, const char *sym_name) {
  void *addr = NULL;

  return addr;
}

int shadowhook_register_dl_init_callback(shadowhook_dl_info_t pre, shadowhook_dl_info_t post, void *data) {
return 0;
}

int shadowhook_unregister_dl_init_callback(shadowhook_dl_info_t pre, shadowhook_dl_info_t post, void *data) {
return 0;
}

int shadowhook_register_dl_fini_callback(shadowhook_dl_info_t pre, shadowhook_dl_info_t post, void *data) {
return 0;
}

int shadowhook_unregister_dl_fini_callback(shadowhook_dl_info_t pre, shadowhook_dl_info_t post, void *data) {
return 0;
}

void *shadowhook_get_prev_func(void *func) {
  return NULL;
}

void shadowhook_pop_stack(void *return_address) {

}

void shadowhook_allow_reentrant(void *return_address) {

}

void shadowhook_disallow_reentrant(void *return_address) {

}

void *shadowhook_get_return_address(void) {
return NULL;
}

#pragma clang diagnostic pop
