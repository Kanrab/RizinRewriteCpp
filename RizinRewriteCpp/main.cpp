#include "Binary/Binary.hpp"
#include "Instructions/Parser.hpp"
#include <fmt/core.h>
#include <vector>

int main(int argc, char *argv[])
{
    // auto binary = Binary { argv[1] };
    // binary.print_elf_executable_header();
    //
    auto instruction_stream = std::vector<std::uint8_t> { 0x48 };
    auto instruction_parser = x86::InstructionParser { instruction_stream };
    instruction_parser.parse_instructions();

    return 0;
}
