 0; i < n; i++)
    {
      cout << i << ": ";
      for (auto i : tree.at(i))
      {
        cout << i << " ";
      }
      cout << endl;
    }
    cout << endl;