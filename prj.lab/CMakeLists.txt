add_library(s21_matrix_oop s21_matrix_oop.cc s21_matrix_oop.h)
set_property(TARGET s21_matrix_oop PROPERTY CXX_STANDARD 17)
target_include_directories(s21_matrix_oop PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS s21_matrix_oop)