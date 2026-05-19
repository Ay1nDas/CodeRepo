#include <gtkmm.h>

class CompactColorTabMockup : public Gtk::Window {
public:
    CompactColorTabMockup() {
        set_title("Color Tab");
        set_default_size(350, 600);
        auto size_group = Gtk::SizeGroup::create(Gtk::SizeGroup::Mode::HORIZONTAL);

        main_box.set_orientation(Gtk::Orientation::VERTICAL);
        main_box.set_margin(16);
        main_box.set_spacing(12);
        set_child(main_box);

        format_hbox.set_orientation(Gtk::Orientation::HORIZONTAL);
        format_hbox.set_spacing(10);

        chk_format.set_label("Format");
        chk_format.set_tooltip_text("Check to explicitly set Color Format");
        chk_format.signal_toggled().connect(sigc::mem_fun(*this, &CompactColorTabMockup::on_format_toggled));
        format_hbox.append(chk_format);

        cmb_format.append("Inherited");
        cmb_format.append("RGB");
        cmb_format.append("CSSNAME");
        cmb_format.append("DeviceCMYK");
        cmb_format.append("HSL");
        cmb_format.append("HSLuv");
        cmb_format.append("OKHsl");
        cmb_format.append("OKLch");
        cmb_format.set_active(0);
        cmb_format.set_sensitive(false);
        cmb_format.set_tooltip_text("Select color space.");

        chk_format.set_hexpand(true);
        cmb_format.set_halign(Gtk::Align::END);
        format_hbox.append(cmb_format);
        main_box.append(format_hbox);

        main_box.append(*Gtk::make_managed<Gtk::Separator>(Gtk::Orientation::HORIZONTAL));

        interp_hbox.set_orientation(Gtk::Orientation::HORIZONTAL);
        interp_hbox.set_spacing(10);

        chk_interp.set_label("Interpolation");
        chk_interp.set_tooltip_text("Check to explicitly set Color Interpolation.");
        chk_interp.signal_toggled().connect(sigc::mem_fun(*this, &CompactColorTabMockup::on_interp_toggled));
        interp_hbox.append(chk_interp);

        cmb_interp.append("Inherited");
        cmb_interp.append("sRGB");
        cmb_interp.append("linearRGB");
        cmb_interp.append("DeviceCMYK");
        cmb_interp.append("HSL");
        cmb_interp.append("OKLch");
        cmb_interp.set_active(0);
        cmb_interp.set_sensitive(false);
        cmb_interp.set_tooltip_text("Select Color Interpolation");

        chk_interp.set_hexpand(true);
        cmb_interp.set_halign(Gtk::Align::END);
        interp_hbox.append(cmb_interp);

        main_box.append(interp_hbox);

        size_group->add_widget(cmb_interp);
        size_group->add_widget(cmb_format);

        main_box.append(*Gtk::make_managed<Gtk::Separator>(Gtk::Orientation::HORIZONTAL));

        expander.set_label("Recolor Selection");
        expander.set_tooltip_text("Recolor Selection");
        
        recolor_area.set_text("Recolor selection area");
        recolor_area.set_halign(Gtk::Align::CENTER);
        recolor_area.set_valign(Gtk::Align::CENTER);
        
        recolor_frame.set_child(recolor_area);
        recolor_frame.set_size_request(-1, 350); 
        recolor_frame.set_margin_top(8);

        expander.set_child(recolor_frame);
        main_box.append(expander);

        main_box.append(*Gtk::make_managed<Gtk::Separator>(Gtk::Orientation::HORIZONTAL));
    }

private:
    void on_format_toggled() {
        bool active = chk_format.get_active();
        cmb_format.set_sensitive(active);
    }

    void on_interp_toggled() {
        bool active = chk_interp.get_active();
        cmb_interp.set_sensitive(active);
    }

    Gtk::Box main_box;
    Gtk::Box format_hbox;
    Gtk::Box interp_hbox;
    
    Gtk::CheckButton chk_format;
    Gtk::ComboBoxText cmb_format;
    
    Gtk::CheckButton chk_interp;
    Gtk::ComboBoxText cmb_interp;

    Gtk::Expander expander;
    Gtk::Frame recolor_frame;
    Gtk::Label recolor_area;
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.inkscape.mockup.compactcolor");
    return app->make_window_and_run<CompactColorTabMockup>(argc, argv);
}

// Compile and Run:
// g++ -std=c++17 color-tab-mockup.cpp -o color-tab-mockup $(pkg-config gtkmm-4.0 --cflags --libs) && ./color-tab-mockup
