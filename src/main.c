#include <gtk/gtk.h>
#include <GL/gl.h>

static const char* path_to_video;
static GtkWidget* where_video;
static GtkWidget* video;
static GFile* video_file;

void click_button(GtkButton* bttn)
{
  path_to_video = gtk_editable_get_text(GTK_EDITABLE(where_video));
  video_file = g_file_new_for_path(path_to_video);

  gtk_video_set_file(GTK_VIDEO(video), video_file);
  g_object_unref(video_file);
}


int main(void)
{
  gtk_init();

  GtkWidget* window = gtk_window_new();

  gtk_window_set_title(GTK_WINDOW(window), "ГОЙДАсмотрительZOVZOVZOVZOV");

  gtk_window_set_default_size(GTK_WINDOW(window), 720, 720);


  GtkWidget* main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  GtkWidget* entry_and_button = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

  video = gtk_video_new();
  gtk_widget_set_size_request(video, 500, 500);
  gtk_widget_set_halign(video, GTK_ALIGN_FILL);
  gtk_widget_set_valign(video, GTK_ALIGN_FILL);

  where_video = gtk_entry_new();
  


  GtkWidget* search_button = gtk_button_new_with_label("Search");


  gtk_box_append(GTK_BOX(entry_and_button), where_video);
  gtk_box_append(GTK_BOX(entry_and_button), search_button);

  gtk_box_append(GTK_BOX(main_box), entry_and_button);
  gtk_box_append(GTK_BOX(main_box), video);

  gtk_window_set_child(GTK_WINDOW(window), main_box);
  gtk_window_present(GTK_WINDOW(window));


  g_signal_connect(search_button, "clicked", G_CALLBACK(click_button), NULL);


  while(g_list_model_get_n_items(gtk_window_get_toplevels()) > 0){
    g_main_context_iteration(NULL, TRUE);
  }

  return 0;
}
