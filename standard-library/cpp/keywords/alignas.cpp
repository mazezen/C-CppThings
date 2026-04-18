#include <type_traits>

int main()
{
    // 指定对齐为 8 字节
    struct alignas(8) S1 { int x; };
    static_assert(alignof(S1) == 8, "S1 应对齐到 8字节");

    // 多个 alignas，取最大值
    class alignas(4) alignas(16) C1 {};
    static_assert(alignof(C1) == 16, "C1 应对齐到 16 字节");

    // 使用类型作为对齐依据
    struct alignas(double) S2 { int x; };
    static_assert(alignof(S2) == alignof(double), "S2 对齐应与 double 相同");
}
