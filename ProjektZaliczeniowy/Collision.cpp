#include "Collision.h"

namespace BreakOut
{
	Collision::Collision() {

	}


	bool Collision::CheckSpriteColision(Sprite sprite1, Sprite sprite2) {
		Rect<float> rect1 = sprite1.getGlobalBounds();
		Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2)) {
			return true;
		}
		else {
			return false;
		}
	}
}