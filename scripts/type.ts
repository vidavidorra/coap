interface Type {
  name: string;
  cppName: string;
  confirmable: boolean;
  acknowledgement: boolean;
  reset: boolean;
}

const types: Type[] = [
  {
    name: 'confirmable',
    cppName: 'kConfirmable',
    confirmable: true,
    acknowledgement: false,
    reset: false,
  },
  {
    name: 'non-confirmable',
    cppName: 'kNonConfirmable',
    confirmable: false,
    acknowledgement: false,
    reset: false,
  },
  {
    name: 'acknowledgement',
    cppName: 'kAcknowledgement',
    confirmable: false,
    acknowledgement: true,
    reset: false,
  },
  {
    name: 'reset',
    cppName: 'kReset',
    confirmable: false,
    acknowledgement: false,
    reset: true,
  },
];

export default types;
export { Type };
