#include "AudioBook.hpp"

AudioBook::AudioBook(std::string title, double length,
                     std::string genre, std::string author,
                     std::string speaker):PlaylistItem(title,length,genre),
                                          author_(author), speaker_(speaker){
} 
                     

std::string AudioBook::getAuthor() const{
    return author_;
}
std::string AudioBook::getSpeaker() const{
    return speaker_;
}

void AudioBook::setAuthor(std::string author){
    author_ = author;
}

void AudioBook::setSpeaker(std::string speaker){
    speaker_ = speaker;
}

void AudioBook::display() const {
    
    std::cout << getTitle() << std::endl
    << "Author: " << author_ << std::endl
    << "Narrator: " << speaker_ << std::endl 
    << "Genre: " << getGenre() << std::endl
    << "Length: " << getLength() << std::endl << std::endl;
}
