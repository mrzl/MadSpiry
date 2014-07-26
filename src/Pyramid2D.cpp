#include "Pyramid2D.h"

Pyramid2D::Pyramid2D( ofVec2f pos, float sizeIncrease, float startZ, float startAngle, float angleIncrease, float angleIncreaseVariation ) :
    m_pos( pos ),
    m_size( 0 ),
    m_sizeIncrease( sizeIncrease ),
    m_startZ( startZ ),
    m_startAngle( startAngle ),
    m_angleIncrease( angleIncrease ),
    m_angleIncreaseVariation( angleIncreaseVariation )
{

}

Pyramid2D::~Pyramid2D()
{

}

void Pyramid2D::addLayer()
{
    std::pair< int, shared_ptr< Layer2D > > p = std::make_pair( m_startZ, shared_ptr< Layer2D > ( new Layer2D( m_pos, m_size, m_startZ, m_startAngle ) ) );
    m_layers.insert( p );

    m_startAngle += m_angleIncrease;
    m_size += m_sizeIncrease;
    m_startZ += 1;
}

void Pyramid2D::draw()
{
    for( std::multimap< int, shared_ptr< Layer2D > >::reverse_iterator it = m_layers.rbegin(); it != m_layers.rend(); ++it )
    {
        std::pair< int, shared_ptr< Layer2D > > pair = *it;
        pair.second->draw();
    }
}

ofVec2f Pyramid2D::getPos()
{
    return m_pos;
}
