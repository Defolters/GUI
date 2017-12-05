#include "CheckButton.h"
#include "../../GUI/GUILayer.h"

CheckButton::CheckButton(std::shared_ptr<GUILayer> layer, RenderWindow * renderWindow_, float x, float y, float width, float height, GUIStyle *gstyle, std::string text, TextStyle* tstyle)
	:GUIBox(renderWindow_, x, y, width, height, gstyle)
{
	for (auto& border : frames)
		border.setColor(Color::Transparent);
	lab = layer->CreateLabel(x + 40, y, text.length() * tstyle->fontSize, width, text, tstyle, gstyle);
	lab->SetHorizontalAlignment(Alignment::LEFT);
	lab->SetDependsOnSize(false);

	sprite.setTexture(gstyle->uncheckedRadBut);
}


void CheckButton::setActive()
{
	sprite.setTexture(gstyle->checkedRadBut);
	active = true;

}

void CheckButton::setDeactive()
{
	sprite.setTexture(gstyle->uncheckedRadBut);
	active = false;
}

bool CheckButton::contain(Vector2f pos)
{
	if (sprite.getGlobalBounds().contains(pos))
		return true;
	else
		return false;
}

void CheckButton::Draw()
{
	GUIBox::Draw();
}

void CheckButton::SetPosition(float x, float y)
{
	GUIBox::SetPosition(x, y);
	lab->SetPosition(x+40, y);
}
void CheckButton::SetPosition(Vector2f position)
{
    GUIBox::SetPosition(position);
    lab->SetPosition(Vector2f(position.x + 40, position.y));
}