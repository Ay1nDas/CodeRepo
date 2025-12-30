#include <gtkmm.h>
#include <iostream>

class ExampleWindow : public Gtk::Window {
public:
    ExampleWindow() {
        set_title("Fixed Popover Test");
        set_default_size(400, 500); // Small window

        // 1. Setup Button
        m_button.set_label("Click Me (Scrolled Fix)");
        m_button.set_valign(Gtk::ALIGN_CENTER);
        m_button.set_halign(Gtk::ALIGN_CENTER);

        // 2. Create the Tall Content (600px)
        auto box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
        box->set_size_request(250, 600); 
        
        auto label_top = Gtk::manage(new Gtk::Label("TOP (Start)"));
        auto label_mid = Gtk::manage(new Gtk::Label("... 600px Content ..."));
        auto label_bot = Gtk::manage(new Gtk::Label("BOTTOM (End)"));

        // Styling for visibility
        auto css = Gtk::CssProvider::create();
        try {
            css->load_from_data("box { background: #e0e0e0; border: 2px solid blue; }");
        } catch(...) {}
        box->get_style_context()->add_provider(css, GTK_STYLE_PROVIDER_PRIORITY_USER);

        box->pack_start(*label_top, false, false);
        box->pack_start(*label_mid, true, true);
        box->pack_start(*label_bot, false, false);

        // 3. THE FIX: Wrap in ScrolledWindow
        // This prevents the "10px crush" bug.
        m_scrolled.add(*box);
        m_scrolled.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
        m_scrolled.set_min_content_height(100); // Allow shrinking down to 100px
        m_scrolled.set_max_content_height(200); // Cap it so it fits on screen
        m_scrolled.set_propagate_natural_height(true);

        // 4. Attach ScrolledWindow to Popover
        m_popover.add(m_scrolled);
        m_button.set_popover(m_popover);

        add(m_button);
        show_all_children();
    }

private:
    Gtk::MenuButton m_button;
    Gtk::Popover m_popover;
    Gtk::ScrolledWindow m_scrolled;
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm3.fix");
    ExampleWindow win;
    return app->run(win, argc, argv);
}