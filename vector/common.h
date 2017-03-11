#pragma once
#ifdef R_OK
#undef R_OK
#endif
#define R_OK 1

#ifdef R_ERR
#undef R_ERR
#endif
#define R_ERR 0