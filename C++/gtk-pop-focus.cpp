#include <gtk/gtk.h>

void activate(GApplication *app, void *)
{
    GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(app));
    
    GtkWidget *button = gtk_menu_button_new();
    gtk_window_set_child(GTK_WINDOW(window), button);
    
    GtkWidget *popover = gtk_popover_new();
    gtk_menu_button_set_popover(GTK_MENU_BUTTON(button), popover);
    
    GtkWidget *scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
    gtk_widget_set_size_request(scale, 200, -1);
    gtk_popover_set_child(GTK_POPOVER(popover), scale);
    gtk_popover_set_autohide(GTK_POPOVER(popover), FALSE);
    
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app = gtk_application_new("org.example.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
}
