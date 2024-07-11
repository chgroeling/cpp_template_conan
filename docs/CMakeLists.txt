set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

set(DOCS_SOURCES
   "${PROJECT_SOURCE_DIR}/include/sample_lib"
  "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.md"
)
doxygen_add_docs(docs ${DOCS_SOURCES})