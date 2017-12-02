 #include "WindowTab.h"

void WindowTab::Resizing(const Event& event_)
{
    Vector2f coefficient;

    for (auto& layer : GUILayers)
    {
        coefficient.x = event_.size.width / layer->GetSize().x;
        coefficient.y = event_.size.height / layer->GetSize().y;
        layer->SetSize(layer->GetSize().x * coefficient.x, layer->GetSize().y * coefficient.y);
        for (auto& element : layer->elements)
        {
            element->SetSize(element->GetSize().x * coefficient.x, element->GetSize().y * coefficient.y);
        }
    }

    window.setView(sf::View(sf::FloatRect(0, 0, event_.size.width, event_.size.height)));
}

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
                Resizing(event);
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
