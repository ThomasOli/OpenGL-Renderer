#pragma once

#include <cstddef>

/***********************************************************************************/
// Forward Declarations
namespace pugi {
class xml_node;
}

struct GLFWwindow;

/***********************************************************************************/
class WindowSystem {
public:
	WindowSystem() = default;
	WindowSystem(const WindowSystem&) = delete;
	WindowSystem& operator=(const WindowSystem&) = delete;

	void Init(const pugi::xml_node& windowNode);
	void Update();
	void Shutdown() const;

	void SetWindowPos(const std::size_t x, const std::size_t y) const;
	void SwapBuffers() const;

	void EnableCursor() const;
	void DisableCursor() const;

	void SetVsync(const bool vsync) const;

	bool ShouldClose() const noexcept { return m_shouldWindowClose; }
	bool IsFocused() const noexcept { return m_focused; }

private:
	GLFWwindow* m_window = nullptr;

	bool m_shouldWindowClose;
	bool m_focused = true;
};