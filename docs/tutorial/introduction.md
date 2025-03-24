import React, { useState } from 'react';
import { View, Text, TextInput, TouchableOpacity, FlatList, StyleSheet } from 'react-native';

export default function App() {
  const [notes, setNotes] = useState([]);
  const [text, setText] = useState('');

  const addNote = () => {
    if (text.trim()) {
      setNotes([...notes, { id: Date.now().toString(), text }]);
      setText('');
    }
  };

  const deleteNote = (id) => {
    setNotes(notes.filter(note => note.id !== id));
  };

  return (
    <View style={styles.container}>
      <Text style={styles.header}>Simple Note-Taking App</Text>
      <TextInput
        style={styles.input}
        placeholder="Write a note..."
        value={text}
        onChangeText={setText}
      />
      <TouchableOpacity style={styles.button} onPress={addNote}>
        <Text style={styles.buttonText}>Add Note</Text>
      </TouchableOpacity>
      <FlatList
        data={notes}
        keyExtractor={(item) => item.id}
        renderItem={({ item }) => (
          <View style={styles.note}>
            <Text style={styles.noteText}>{item.text}</Text>
            <TouchableOpacity onPress={() => deleteNote(item.id)}>
              <Text style={styles.delete}>Delete</Text>
            </TouchableOpacity>
          </View>
        )}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, padding: 20, backgroundColor: '#f5f5f5' },
  header: { fontSize: 24, fontWeight: 'bold', marginBottom: 10, textAlign: 'center' },
  input: { height: 50, borderColor: '#ddd', borderWidth: 1, paddingHorizontal: 10, marginBottom: 10, borderRadius: 5, backgroundColor: '#fff' },
  button: { backgroundColor: '#007bff', padding: 15, borderRadius: 5, alignItems: 'center' },
  buttonText: { color: '#fff', fontSize: 16, fontWeight: 'bold' },
  note: { flexDirection: 'row', justifyContent: 'space-between', padding: 15, backgroundColor: '#fff', borderRadius: 5, marginTop: 10 },
  noteText: { fontSize: 16 },
  delete: { color: 'red', fontWeight: 'bold' }
});
