 #include "WindowTab.h"

std::shared_ptr<GUILayer> WindowTab::CreateGUILayer(Vector2f position_, Vector2f size_)
{
	GUILayers.push_back(std::shared_ptr<GUILayer>(new GUILayer(window, position_, size_)));
	return GUILayers[GUILayers.size() - 1];
}

void WindowTab::Redraw()
{
	if (state == opened)
	{
		window.clear();
		Event event;
		while (window.pollEvent(event))
		{
			notifyAll(event);
			if (event.type == Event::Closed)
			{
				window.close();
				state = closed;
			}
            else if (event.type == sf::Event::Resized)
            {
                Vector2f coefficient;
                coefficient.x = 0.5;//800 / window.getSize().x;
                coefficient.y = 0.5;//600 / window.getSize().y;

                for (auto& layer : GUILayers)
                {
                    for (auto& element : layer->elements)
                    {
                        std::cout << "Resizing \n";
                        element->SetSize(element->GetSize().x * coefficient.x, element->GetSize().y * coefficient.y);
                    }
                    //layer->GetElement().getsize;
                    //setsize;
                }
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
		}
		for (auto& layer : GUILayers)
			layer->Draw();
		window.display();
	}
}

WindowTab::WindowTab(VideoMode mode, char * name) : window (mode,name)
{
	state = opened;
}

void WindowTab::removeElement(IDrawable* observer)
{

}

void WindowTab::notifyAll(const sf::Event & event) const
{
	for (auto& layer : GUILayers)
		layer->handleEvent(event);
}

WindowTab::~WindowTab()
{
}
