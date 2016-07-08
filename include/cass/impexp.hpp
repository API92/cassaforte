/*
 * Copyright (C) Andrey Pikas
 */

#pragma once

#if defined(CASSA_EXPORTS)
#   define CASSA_IMPEXP __attribute__ ((visibility("default")))
#else
#   define CASSA_IMPEXP
#endif
