// RUN: ast -f test -- -std=c++11 "%s" 2>&1 | FileCheck %s

// CHECK: EnumDecl
// CHECK-NEXT:   DeclarationName test1
// CHECK-NEXT:   EnumType
// CHECK-NEXT:   EnumConstantDecl
// CHECK-NEXT:   EnumConstantDecl
enum test1 {
  A1,
  B1
};

class A {
  // CHECK-NEXT: EnumDecl
  // CHECK-NEXT:   DeclarationName test2
  // CHECK-NEXT:   BuiltinType unsigned int
  // CHECK-NEXT:   EnumType
  enum test2 : unsigned int;

  // CHECK-NEXT: EnumDecl
  // CHECK-NEXT:   DeclarationName test3
  // CHECK-NEXT:   EnumType
  enum class test3;
};

// CHECK-NEXT: EnumDecl
// CHECK-NEXT:   DeclarationName test2
// CHECK-NEXT:   BuiltinType unsigned int
// CHECK-NEXT:   EnumType
// CHECK-NEXT:   NestedNameSpecifier A::
// CHECK-NEXT:     RecordType A
// CHECK-NEXT:   EnumConstantDecl
// CHECK-NEXT:   EnumConstantDecl
enum A::test2 : unsigned int {
  A2,
  B2
};

// CHECK-NEXT: EnumDecl
// CHECK-NEXT:   DeclarationName test3
// CHECK-NEXT:   EnumType
// CHECK-NEXT:   NestedNameSpecifier A::
// CHECK-NEXT:     RecordType A
// CHECK-NEXT:   EnumConstantDecl
// CHECK-NEXT:   EnumConstantDecl
enum class A::test3 {
  A3,
  B3
};