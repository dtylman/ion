#include "Routing.h"

Routing::Routing()
{
    load4();
    load6();
}

Routing::~Routing()
{
}

const Routing::Gateways& Routing::gateways() const
{
    return _gateways;
}
