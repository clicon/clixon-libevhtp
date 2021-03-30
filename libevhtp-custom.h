
#define EVHTP_DISABLE_REGEX
#define EVHTP_DISABLE_EVTHR
#undef EVHTP_DEBUG
    
#undef EVHTP_DISABLE_EVTHR
#undef EVHTP_DISABLE_SSL
#undef EVHTP_DISABLE_SSL
#undef EVHTP_USE_TCMALLOC
#undef EVHTP_USE_JEMALLOC
#undef EVHTP_USE_TCMALLOC
#undef EVHTP_DISABLE_MEMFUNCTIONS

# if (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER || defined __clang__
#  define EVHTP_EXPORT __attribute__ ((visibility("default")))
# else
#  define EVHTP_EXPORT
# endif


