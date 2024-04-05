#include "Application.h"

Application* Application::GetInstacne() {
  if (instance == nullptr) {
    instance = new Application;
  }
  return instance;
}

Application::Application() {
  widget_container = new Widget;
  widget_container->SetLayout(new QVBoxLayout);
}

void Application::Exec() {
  instance->widget_container->ShowMaximized();
}

void Application::AddWidget(QWidget* new_widget) {
  instance->widget_container->GetLayout()->addWidget(new_widget);
  instance->widget_container->SetLayout(instance->widget_container->GetLayout());
}

QWidget* Application::DeleteWidget(QWidget* widget_to_delete) {
  instance->widget_container->GetLayout()->removeWidget(widget_to_delete);
  instance->widget_container->SetLayout(instance->widget_container->GetLayout());
  return widget_to_delete;
}

void Application::AddWidget(Widget* new_widget) {
  instance->widget_container->GetLayout()->addWidget(new_widget);
  instance->widget_container->SetLayout(instance->widget_container->GetLayout());
}

Widget* Application::DeleteWidget(Widget* widget_to_delete) {
  instance->widget_container->GetLayout()->removeWidget(widget_to_delete);
  instance->widget_container->SetLayout(instance->widget_container->GetLayout());
  return widget_to_delete;
}

void Application::Init() {
  if (instance == nullptr) {
    instance = new Application;
  }
}
