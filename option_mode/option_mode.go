package main

import "fmt"

type Person struct {
	ID   int    `json:"id"`
	Name string `json:"name"`
}

func (p *Person) String() string {
	return fmt.Sprintf("%d %s", p.ID, p.Name)
}

type OptionFunc func(*Person)

func CreatePerson(opts ...OptionFunc) *Person {
	person := &Person{
		ID:0,
		Name:"",
	}

	for _, opt := range opts {
		opt(person)
	}

	return person
}

func WithID(id int) OptionFunc {
	return func(opts *Person) {
		opts.ID = id
	}
}

func WithName(name string) OptionFunc {
	return func(opts *Person) {
		opts.Name = name
	}
}

func main() {
	p := CreatePerson(WithID(123))
	fmt.Println(p)

	p = CreatePerson(WithName("tom"))
	fmt.Println(p)

	p = CreatePerson(WithID(123), WithName("tom"))
	fmt.Println(p)
}