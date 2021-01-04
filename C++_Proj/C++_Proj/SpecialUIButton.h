#pragma once
#include "UI_Button.h"
#include "Label.h"
#include "MainWIndow.h"
#include <functional>

template<typename RETURNTYPE, typename OBJ_TYPE, typename...arguments>
struct Callback {
	RETURNTYPE (OBJ_TYPE::*function)(arguments...);
	OBJ_TYPE* object;
};

template<typename RETURNTYPE, typename OBJ_TYPE, typename...arguments>
class SpecialUIButton : public UI_Button {
public:
	static SpecialUIButton<RETURNTYPE, OBJ_TYPE, arguments...>* create_instance(int, int, int, int, SDL_Texture*, std::string text, Callback<RETURNTYPE, OBJ_TYPE, arguments...>*);
	void tick() override {}
	void draw() const override;
	RETURNTYPE invoke(arguments...) const;
private:
	SpecialUIButton<RETURNTYPE, OBJ_TYPE, arguments...>(int, int, int, int, SDL_Texture*, std::string, Callback<RETURNTYPE, OBJ_TYPE, arguments...>*);
	Label* label;
	Callback<RETURNTYPE, OBJ_TYPE, arguments...>* callback;
	SDL_Texture* texture;
};

template<typename RETURNTYPE, typename OBJ_TYPE, typename...arguments>
SpecialUIButton<RETURNTYPE, OBJ_TYPE, arguments...>* SpecialUIButton<RETURNTYPE, OBJ_TYPE, arguments...>::create_instance(int x, int y, int w, int h, SDL_Texture* texture, std::string text, Callback<RETURNTYPE, OBJ_TYPE, arguments...>* callback) {
	return new SpecialUIButton(x, y, w, h, texture, text, callback);
}

template<typename RETURNTYPE, typename OBJ_TYPE, typename...arguments>
inline void SpecialUIButton<RETURNTYPE, OBJ_TYPE, arguments...>::draw() const {
	if (!texture)
		label->draw();
	else
		SDL_RenderCopy(&gameSystem.get_renderer(), texture, NULL, &get_rect());

}

template<typename RETURNTYPE, typename OBJ_TYPE, typename ...arguments>
inline RETURNTYPE SpecialUIButton<RETURNTYPE, OBJ_TYPE, arguments...>::invoke(arguments...args) const {
	return callback->(object->*function)(args...);
}
template<typename RETURNTYPE, typename OBJ_TYPE, typename...arguments>
SpecialUIButton<RETURNTYPE, OBJ_TYPE, arguments...>::SpecialUIButton(int x, int y, int w, int h, SDL_Texture* texture, std::string text, Callback<RETURNTYPE, OBJ_TYPE, arguments...>* callback) :
	Component(x, y, w, h),
	texture(texture),
	label(Label::getInstance(x, y, w, h, text, { 255, 255, 255, 255 })),
	callback(callback) {
}