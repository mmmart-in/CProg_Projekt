#pragma once

#include <string>
#include <vector>

template<typename T>
class SceneContents {
public:
	void add(T*);
	void remove(T*);
	void clear_vectors();
	const std::vector<T*>& get_added() const;
	const std::vector<T*>& get_removed() const;
	const unsigned int get_scene_index() const;
	const std::string get_scene_name() const;
private:
	std::vector<T*> added, removed;
};

template<typename T>
inline void SceneContents<T>::add(T* object) {
	added.push_back(object);
}

template<typename T>
inline void SceneContents<T>::remove(T* object) {
	removed.push_back(object);
}

template<typename T>
inline void SceneContents<T>::clear_vectors() {
	added.clear();
	removed.clear();
}

template<typename T>
inline const std::vector<T*>& SceneContents<T>::get_added() const {
	return added;
}

template<typename T>
inline const std::vector<T*>& SceneContents<T>::get_removed() const {
	return removed;
}

template<typename T>
inline const unsigned int SceneContents<T>::get_scene_index() const {
	return scene_index;
}

template<typename T>
inline const std::string SceneContents<T>::get_scene_name() const {
	return scene_name;
}

