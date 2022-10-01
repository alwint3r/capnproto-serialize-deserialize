#include <iostream>
#include <fstream>
#include <kj/std/iostream.h>
#include <capnp/serialize-packed.h>
#include <capnp/message.h>
#include "person.capnp.h"

int main()
{
    std::ifstream ifs;
    ifs.open("person.bin");

    kj::std::StdInputStream input(ifs);
    kj::BufferedInputStreamWrapper bufferedInput(input);
    capnp::PackedMessageReader message(bufferedInput);

    Person::Reader person = message.getRoot<Person>();

    std::cout << "ID = " << person.getId() << ", Name = " << person.getName().cStr() << std::endl;

    return 0;
}