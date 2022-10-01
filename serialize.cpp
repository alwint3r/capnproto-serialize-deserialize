#include <iostream>
#include <fstream>
#include <kj/std/iostream.h>
#include <capnp/serialize-packed.h>
#include <capnp/message.h>
#include "person.capnp.h"

int main()
{
    capnp::MallocMessageBuilder message;
    Person::Builder personBuilder = message.initRoot<Person>();

    personBuilder.setId(27);
    personBuilder.setName("Winter");

    std::ofstream ofs;
    ofs.open("person.bin");

    kj::std::StdOutputStream output(ofs);
    writePackedMessage(output, message);

    return 0;
}