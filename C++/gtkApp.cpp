#include <gtkmm.h>
#include <iostream>

// 1. Create a custom window class
class MyWindow : public Gtk::Window
{
public:
  MyWindow(); // Constructor

protected:
  // 2. Declare widget members
  Gtk::Button m_button;

  // 3. Signal handler (function called when button is clicked)
  void on_button_clicked();
};

// Constructor implementation
MyWindow::MyWindow()
{
  // Set window title
  set_title("My C++ App");
  set_default_size(300, 100);

  // Initialize the button
  m_button.set_label("Click Me!");
  m_button.set_margin(10); // Add spacing around the button

  // 4. Connect the button's "clicked" signal to our function
  // This replaces standard C function pointers with C++ slots
  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &MyWindow::on_button_clicked));

  // 5. Add the button to the window
  set_child(m_button);
}

// Signal handler implementation
void MyWindow::on_button_clicked()
{
  std::cout << "Button was clicked!" << std::endl;
  m_button.set_label("Clicked!");
}

int main(int argc, char *argv[])
{
  // 6. Create the application object (required for every GTK app)
  auto app = Gtk::Application::create("org.gtkmm.example.base");

  // 7. Run the application with our custom window
  // This simplifies the "main loop" process
  return app->make_window_and_run<MyWindow>(argc, argv);
}