#include "tests.h"

std::unique_ptr<Texture> MakeTextureCow() {
    Image image = { R"(^__^            )",  //
                   R"((oo)\_______    )",  //
                   R"((__)\       )\/\)",  //
                   R"(    ||----w |   )",  //
                   R"(    ||     ||   )" };
    return std::make_unique<Texture>(move(image));
}

void TestCow() {
    Canvas canvas{ {18, 5} };

    canvas.AddShape(ShapeType::RECTANGLE, { 1, 0 }, { 16, 5 }, MakeTextureCow());

    std::stringstream output;
    canvas.Print(output);
    std::cout << output.str();

    // clang-format off
    // Здесь уместно использовать сырые литералы, т.к. в текстуре есть символы '\'
    const auto answer =
        R"(####################)""\n"
        R"(# ^__^             #)""\n"
        R"(# (oo)\_______     #)""\n"
        R"(# (__)\       )\/\ #)""\n"
        R"(#     ||----w |    #)""\n"
        R"(#     ||     ||    #)""\n"
        R"(####################)""\n";
    // clang-format on

    assert(answer == output.str());
}
